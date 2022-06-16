package main

import (
	"fmt"
	"time"
)

func main() {

	var msg string
	fmt.Print("Enter a message = ")
	fmt.Scanln(&msg)

	go encode(msg)
	go hash(msg)

	time.Sleep(time.Second * 1)
	fmt.Println("Encoded message = ", encode(msg))
	fmt.Println("Hash value = ", hash(msg))
	fmt.Println("Encoding1_Hash = ", msg+"_"+msg)
}

func encode(msg string) string {
	str := ""
	for i := 0; i < len(msg); i++ {
		if msg[i] == 'a' || msg[i] == 'e' || msg[i] == 'i' || msg[i] == 'o' || msg[i] == 'u' {
			str = str + "*"
		} else {
			str = str + string(msg[i])
		}
	}
	return str
}

func hash(msg string) int {
	var count int
	var vowel int
	for i := 0; i < len(msg); i++ {
		if msg[i] == 'a' || msg[i] == 'e' || msg[i] == 'i' || msg[i] == 'o' || msg[i] == 'u' {
			vowel++
		}
	}
	count = len(msg) * vowel
	return count
}
