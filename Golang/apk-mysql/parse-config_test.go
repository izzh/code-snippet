package apkMysql

import (
    "testing"
    "fmt"
)

func Test_ParseJson(t *testing.T) {
    var db DBInfo

    if err := ParseJson("./db.json", &db); err == nil {
        fmt.Println("mysql info:", db.Host, db.Port, db.User, db.Password, db.DBName)
        t.Log("testing pass!")
    } else {
        t.Error("testing fail!")
    }
}
