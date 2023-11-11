package main

import (
    "fmt"
    "syscall"
    "strings"
    "os"
)

func main() {
    var uname syscall.Utsname
    ansiReset := "\033[0m"
    ansiBold := "\033[1m"
    if err := syscall.Uname(&uname); err != nil {
        fmt.Println(err)
        return
    }

    kernelVersion := strings.Trim(utsnameStr(uname.Release[:]), "\x00")
    hostname, _ := os.Hostname()
    fmt.Println(ansiBold + "KERNEL:" + ansiReset, kernelVersion)
    fmt.Println(ansiBold + "HOST:" + ansiReset, hostname)
    fmt.Println(ansiBold + "LOCALE:" + ansiReset, os.Getenv("LANG"))
    fmt.Println(ansiBold + "USER:" + ansiReset, os.Getenv("USER"))
}

// utsnameStr converts a slice of bytes to a string, trimming any trailing NUL bytes.
func utsnameStr(s []byte) string {
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] != 0 {
            return string(s[:i+1])
        }
    }
    return ""
}
