// Program in Go language to find mean , variance and standard deviation

package main

import (
	"fmt"
)

//Function to calculate Greatest Common Divisor based on Euclid's Method
func egcd(a int, b int) int {
	var rem int
	for b != 0 {
		rem = a % b
		a = b
		b = rem
	}
	return a
}

// Function to calculate power integer numbers
// This is because in Go, by default we have only for float64 numbers
func ipow(base int, exp int) int {
	var result int = 1
	for exp != 0 {
		result *= base
		exp--
	}
	return result
}

func main() {
	// m is message to be encrypted, 1 < m < n
	var m, p, q, phi, e, d, n, c, temp, message int

	fmt.Print("Enter numeric text message : ")
	fmt.Scan(&m)

	// p & q are two random prime numbers
	p = 5
	q = 7
	n = p * q

	// Eulers Toitent Function
	phi = (p - 1) * (q - 1)

	//(n,e) forms our public key, 1 < e < phi
	e = 2
	for e < phi {
		if egcd(e, phi) == 1 {
			break
		}
		e++

	}

	// (n,d) forms our private key, 1 < d < phi
	d = 2
	for d < phi {
		temp = ((e * d) - 1) % phi
		if temp == 0 {
			break
		}
		d++
	}

	// printing cipher text
	c = ipow(m, e) % n
	fmt.Println("\nCipher = ", c)

	// printing original message
	message = ipow(c, d) % n
	fmt.Println("\nMessage = ", message)
}
