package main

import (
	"fmt"
	"net/rpc"
)

type Paper struct {
	Title   string
	Author  string
	Journal string
	Volume  int
	Year    int
}

type PaperList struct {
	List []Paper
}

func main() {

	client, err := rpc.DialHTTP("tcp", "localhost:1234")
	if err != nil {
		fmt.Println("Error in connecting to the server")
		return
	}

	// Create a new paper
	var p1 = Paper{"The Go Programming Language", "Alan A. A. Donovan", "Journal of Go", 1, 2009}
	var p2 = Paper{"Go Concurrency Patterns", "Brian W. Kernighan", "Go Concurrency Cookbook", 2, 2012}
	var p3 = Paper{"Go in Action", "Brian W. Kernighan", "Go in Action", 3, 2016}

	// Create a new paper list
	var pl = PaperList{make([]Paper, 3)}
	pl.List[0] = p1
	pl.List[1] = p2
	pl.List[2] = p3

	// Call the server method
	var reply bool
	err = client.Call("PaperServer.Add", pl, &reply)
	if err != nil {
		fmt.Println("Error in calling the server")
		return
	}
	fmt.Println("Server reply: ", reply)
}
