package apkMysql

import (
	"testing"
)

func Test_MD5Sum(t *testing.T) {
	if md5, err := MD5Sum("./22.apk"); err != nil {
		t.Error("testing md5 fail!")
	} else {
		t.Log("MD5: ", md5)
		t.Log("testing md5 pass!")
	}
}
