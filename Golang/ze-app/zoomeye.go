package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

const accountFile = "account.json"

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
	resp, err := http.Post("https://api.zoomeye.org/user/login", "application/json;charset=utf-8", body)
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

func main() {
	accessToken := make(map[string]string)
	err := getAccessToken(accessToken)
	if err != nil {
		log.Println("get access token fail!")
		return
	}

	fmt.Printf("access_token:%s\n", accessToken["access_token"])

    // search
    client := &http.Client{}
    req, err := http.NewRequest("GET", "https://api.zoomeye.org/host/search?query=port:23&city:nanjing&page=1&facet=app,os", nil)
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
    fmt.Printf("%s\n", body)
}
