package main

import (
    "fmt"
)

func main() {
    type tag struct {
        name string

        attr struct {
            owner int
            pem int
        }
    }

    f := tag {
        name : "test",
        // attr : {
        //     owner : 1024,
        //     pem : 256,
        // },
    }
    f.attr.owner = 256
    f.attr.pem = 1024

    fmt.Printf("struct: %v\n", f)
}
