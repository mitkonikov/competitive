package main

import "fmt"

func swap(a, b string)(string, string) {
	return b, a
}

func addBinary(a string, b string) string {
    var result string = ""

	if len(b) < len(a) {
		a, b = swap(a, b)
	}

	var paddingSize int = len(b) - len(a)
	var padding string = ""
	for i := 0; i < paddingSize; i++ {
		padding = padding + "0"
	}

	a = padding + a

	var carry int = 0
	for i := len(a) - 1; i >= 0; i-- {
		carry += int(a[i] - '0')
		carry += int(b[i] - '0')
		if carry & 1 == 1 {
			result += "1"
		} else {
			result += "0"
		}
		carry = carry / 2
	}

	if carry > 0 {
		result += "1"
	}

	var reversed string = ""
    for i := len(result) - 1; i >= 0; i-- {
        reversed += string(result[i])
    }

    return reversed
}