package main

import (
    "fmt"
    "reflect"
)

type X int

func  main() {
    var a X
    r := reflect.TypeOf(a)

    // X int
    fmt.Println(r.Name(), r.Kind())

    // Elem()
    fmt.Println(reflect.TypeOf(map[string]int{}).Elem())

    // value
    x := 100
    va, vp := reflect.ValueOf(x), reflect.ValueOf(&x).Elem()

    fmt.Println(va.CanAddr(), va.CanSet())
    fmt.Println(vp.CanAddr(), vp.CanSet())

    // interface
    type user struct {
        Name string
        Age int
    }

    u := user {
        Name : "zzh",
        Age : 25,
    }

    v := reflect.ValueOf(&u)
    if !v.CanInterface() {
        fmt.Println("Interface fail.")
        return
    }

    p, ok := v.Interface().(*user)
    if !ok {
        fmt.Println("Interface fail.")
        return
    }

    p.Age++
    fmt.Printf("%+v\n", u)
}
