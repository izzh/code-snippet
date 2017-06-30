package main

import (
    "time"
    "fmt"
)

func main() {
    tick := time.Tick(2 * time.Second)

    for {
        select {
        case <- tick:
            fmt.Printf("tick\n")
        }
    }
}
