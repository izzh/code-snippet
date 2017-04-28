package apkMysql

import (
	"encoding/json"
	"io/ioutil"
	"log"
)

type DBInfo struct {
	Host     string
	Port     string
	User     string
	Password string
	DBName   string
}

func ParseJson(file string, db *DBInfo) (err error) {
	b, err := ioutil.ReadFile(file)
	if err != nil || b == nil {
		log.Fatalln("read db config file fail!")
	}

	err = json.Unmarshal(b, db)
	if err != nil {
		log.Println("parse json fail!")
	}

	return
}
