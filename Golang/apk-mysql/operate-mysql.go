package apkMysql

import (
	"database/sql"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"log"
)

const (
	createWhiteList = "CREATE TABLE 'whitelist' ( 'whitelist_id' INT(11) NOT NULL AUTO_INCREMENT, 'whitelist_md5' VARCHAR(64) NULL DEFAULT NULL, 'whitelist_value' INT(11) NULL DEFAULT '0', 'appinfo_id' INT(11) DEFAULT NULL, PRIMARY KEY('whitelist_id'), FOREIGN KEY(appinfo_id) REFERENCES appinfo(appinfo_id))"
	insertWhiteList = "INSERT whitelist SET whitelist_md5=?,whitelist_value=?,appinfo_id=?"
	selectAppInfo   = "SELECT appinfo_id, appinfo_name FROM appinfo WHERE appinfo_done = 0 ORDER BY appinfo_id LIMIT 1;"
	selectMD5       = "SELECT appinfo_id FROM appinfo WHERE appinfo_done = 1 AND appinfo_md5=? ORDER BY appinfo_id LIMIT 1;"
	updateAppinfo   = "UPDATE appinfo SET appinfo_md5 = ?, appinfo_done=1 WHERE appinfo_id = ?"
)

// func GenerateWhiteList(dbInfo string) (err error) {
//     db, err := sql.Open("mysql", dbInfo)
//     if err != nil {
//         log.Println("open mysql fail!")
//         return
//     }
//     defer db.CLose()
//
//     _, err = db.Exec(createWhiteList)
//     if err != nil {
//         log.Println("create table white list fail!")
//     }
// }

func EliminateRepeatAPK(dbInfo string) (err error) {
	db, err := sql.Open("mysql", dbInfo)
	if err != nil {
		log.Println("mysql", dbInfo)
		return
	}
	defer db.Close()

	rows, err := db.Query(selectAppInfo)
	if err != nil {
		log.Println("select from appinfo fail!")
		return
	}

	var appinfo_id int
	var appinfo_name string
	var appinfo_md5 string
	for rows.Next() {
		err = rows.Scan(&appinfo_id, &appinfo_name)

		appinfo_md5, err = MD5Sum("/opt/apptest/apk" + appinfo_name)
		if err != nil {
			log.Println("compute " + appinfo_name + "md5 fail!")
			continue
		}
		var result int
		err = db.QueryRow(selectMD5, appinfo_md5).Scan(&result)
		if err != nil || result == 0 {
			log.Printf("query md5 Result: %d\n", result)
			continue
		}
		stmt, err := db.Prepare(updateAppinfo)
		if err != nil {
			log.Println("update appinfo fail!")
			continue
		}

		res, err := stmt.Exec(appinfo_md5, appinfo_id)
		if err != nil {
			log.Println("update Exec fail!")
			continue
		}
		affect, err := res.RowsAffected()
		if err != nil {
			log.Println("update RowAffected fail!")
		}
		fmt.Println(affect)
	}

	return
}
