package apkMysql

import (
    "database/sql"
    _ "github.com/go-sql-driver/mysql"
    "log"
)

const (
    createWhiteList = "CREATE TABLE 'whitelist' (
        'whitelist_id' INT(11) NOT NULL AUTO_INCREMENT,
        'whitelist_md5' VARCHAR(64) NULL DEFAULT NULL,
        'whitelist_value' INT(11) NULL DEFAULT '0',
        'appinfo_id' INT(11) DEFAULT NULL,
        PRIMARY KEY('whitelist_id'),
        FOREIGN KEY(appinfo_id) REFERENCES appinfo(appinfo_id)
    )"
    insertWhiteList = "INSERT whitelist SET whitelist_md5=?,whitelist_value=?,appinfo_id=?"
    selectAppInfo = ""
)

func GenerateWhiteList(dbInfo string) (err error) {
    db, err := sql.Open("mysql", dbInfo)
    if err != nil {
        log.Println("open mysql fail!")
        return
    }
    defer db.CLose()
}

func EliminateRepeatAPK(dbInfo string) (err error) {
    db, err := sql.Open("mysql", dbInfo)
}
