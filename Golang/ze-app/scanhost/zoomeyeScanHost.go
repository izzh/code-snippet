package scanhost

import (
	"bytes"
	"encoding/json"
	"fmt"
	"github.com/bitly/go-simplejson"
	"io/ioutil"
	"log"
	"net/http"
)

const (
	accountFile = "conf/account.json"
	configFile  = "conf/config.json"
    login_api = "https://api.zoomeye.org/user/login"
    search_api = "https://api.zoomeye.org/host/search?query=port:23&page=%d&facet=app,os"
)

func readJsonFile(file string) ([]byte, error) {
	b, err := ioutil.ReadFile(file)
	if err != nil || b == nil {
		log.Fatalln("read json file fail!")
	}

	return b, err
}

func getAccessToken(m map[string]string) (err error) {
	accountInfo, _ := readJsonFile(accountFile)
	body := bytes.NewBuffer(accountInfo)
	resp, err := http.Post(login_api, "application/json;charset=utf-8", body)
	if err != nil {
		log.Println("http post fail!")
	}

	defer resp.Body.Close()
	accessToken, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Println("read token from resp fail!")
		return
	}

	err = json.Unmarshal(accessToken, &m)
	if err != nil {
		log.Println("decode token json fail!")
	}
	return
}

func GetHostList(message chan string) {
	accessToken := make(map[string]string)
	err := getAccessToken(accessToken)
	if err != nil {
		log.Println("get access token fail!")
		return
	}

	// fmt.Printf("access_token:%s\n", accessToken["access_token"])

	// search
	client := &http.Client{}
	for i := 1; i <= 1000; i++ {
        url := fmt.Sprintf(search_api, i)
		req, err := http.NewRequest("GET", url, nil)
		if err != nil {
			log.Printf("http NewRequst fail!")
			return
		}
		req.Header.Add("Authorization", "JWT "+accessToken["access_token"])
		resp, err := client.Do(req)
		if err != nil {
			log.Printf("client Do fail!")
			return
		}
		defer resp.Body.Close()
		body, err := ioutil.ReadAll(resp.Body)
		if err != nil {
			log.Printf("read body fail!")
		}
		// fmt.Printf("%s\n", body)

		// parse
		js, err := simplejson.NewJson(body)
		if err != nil || js == nil {
			log.Println("parse search result fail!")
		}
		matchin, err := js.Get("matches").Array()
		if err != nil {
			log.Printf("search result return: %s\n", body)
		}
		// fmt.Println(matchin)
        cnt := 0
		for _, value := range matchin {
            cnt++
			node, _ := value.(map[string]interface{})
			// isp := node["geoinfo"].(map[string]interface{})["isp"]
            ip := node["ip"]
            service := node["portinfo"].(map[string]interface{})["service"]
            port := node["portinfo"].(map[string]interface{})["port"]
            app := node["portinfo"].(map[string]interface{})["app"]
            device := node["portinfo"].(map[string]interface{})["device"]
            os := node["portinfo"].(map[string]interface{})["os"]
            timestamp := node["timestamp"]

			fmt.Printf("%-5v %-16v %-16v %-5v %-48v %-20v %-16v %-20v\n",
				(i-1)*10 + cnt, ip, service, port, app, device, os, timestamp)
		}
	}
	message <- "get host list over!"
}
