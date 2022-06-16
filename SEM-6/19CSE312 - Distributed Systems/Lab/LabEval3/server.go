//Write a server program for mattern's algorithm


package main

import (
	"fmt"
	"net"
	"os"
	"strconv"
	"strings"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Usage: ", os.Args[0], " port")
		os.Exit(1)
	}
	service := ":" + os.Args[1]
	tcpAddr, err := net.ResolveTCPAddr("tcp4", service)
	checkError(err)
	listener, err := net.ListenTCP("tcp", tcpAddr)
	checkError(err)
	for {
		conn, err := listener.Accept()