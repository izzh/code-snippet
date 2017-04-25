package apkMysql

import (
    "os"
    "log"
    "crypto/md5"
    "io"
    "fmt"
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

