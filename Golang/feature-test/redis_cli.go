package main

import (
    "fmt"
    "github.com/garyburd/redigo/redis"
    "encoding/json"
)

type JData struct {
    Name string
}

func main() {
    option := redis.DialPassword("admin@yxzc!@")
    c, err := redis.Dial("tcp", "localhost:6379", option)
    if err != nil {
        fmt.Printf("conn redis fail!\n")
        return
    }

    defer c.Close()
    c.Do("PUBLISH", "CCAttack", "hello")

    psc := redis.PubSubConn{Conn : c}
    psc.Subscribe("foo")
    var jd JData
    for {
        switch v := psc.Receive().(type) {
        case redis.Message:
            fmt.Printf("%s: message: %s\n", v.Channel, v.Data)
            json.Unmarshal([]byte(v.Data), &jd)
            fmt.Println(jd)
        case redis.Subscription:
            fmt.Printf("%s: %s %d\n", v.Channel, v.Kind, v.Count)
        case error:
            return
        }

    }
}
