package main

import (
	"fmt"
)

const search_api = "https://api.zoomeye.org/host/search?query=port:23&page=%d&facet=app,os"

func main() {
	var new_api string

	for i := 0; i < 10; i++ {
		new_api = fmt.Sprintf(search_api, i)
		fmt.Println(new_api)
	}
}
