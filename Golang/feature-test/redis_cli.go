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
    c, err := redis.Dial("tcp", "192.168.40.146:6379", option)
    if err != nil {
        fmt.Printf("conn redis fail!\n")
        return
    }

    defer c.Close()
    // c.Do("PUBLISH", "CCAttack", "hello")
    result, _ := c.Do("CLIENT", "LIST")
    fmt.Printf("clients: %s\n", result)
    switch v := result.(type) {
    case string:
        fmt.Printf("clients: %v, %v\n", v, result)
    case error:
        return
    }

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
