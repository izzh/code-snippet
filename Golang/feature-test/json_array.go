package main

import (
    "encoding/json"
    "fmt"
)

type Users struct {
    Names []string
}

func main() {
    arr := []byte(`{"names" : ["uuu", "ccc", "ttt", "fdjsk", "fjkdsaf", "pppp", "qqqq", "bbb", "sasas", "nnnn", "vvvv"]}`)
    arr1 := []byte(`{"Names" : ["11111"]}`)

    var u Users
    json.Unmarshal(arr, &u)
    fmt.Printf("json: %v\n", u)

    var u2 Users
    json.Unmarshal(arr1, &u2)
    if len(u2.Names) == 0 {
        fmt.Printf("parse nothing\n")
    }
    fmt.Printf("json1: %v\n", u2)
}
