package apkMysql

import (
	"crypto/md5"
	"fmt"
	"io"
	"log"
	"os"
)

func MD5Sum(file string) (md5sum string, err error) {
	f, err := os.Open(file)
	if err != nil {
		log.Println("Open apk file fail!")
		return
	}
	defer f.Close()

	h := md5.New()
	if _, err = io.Copy(h, f); err != nil {
		log.Println("copy apk file fail!")
		return
	}
	md5sum = fmt.Sprintf("%x", h.Sum(nil))

	return
}
