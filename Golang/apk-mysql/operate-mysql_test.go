package apkMysql

import (
	"testing"
)

func Test_EliminateRepeatAPK(t *testing.T) {
    dbInfo := "root:szdhp1211@tcp(192.168.40.15:3306)/androidscanner?charset=utf8"
	if err := EliminateRepeatAPK(dbInfo); err != nil {
		t.Error("testing EliminateRepeatAPK fail!")
	} else {
		t.Log("testing EliminateRepeatAPK pass!")
	}
}
