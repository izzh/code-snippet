package main

import (
	"./scanhost"
	"fmt"
)

func main() {
	msg := make(chan string)
	fmt.Println("start get scanhost...")

	go scanhost.GetHostList(msg)

	content := <-msg
	fmt.Println(content)
}
