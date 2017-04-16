import (
    "os"
)

func readAccountFile(b []byte) (int, error) {
    filePath := "account.json"

    f, err := os.Open(filePath)
    defer f.Close()
    if err != nil {
        log.Fatalln("Open file fail!")
    }

    n, err := f.Read(b)
    if err != nil || n == 0 {
        log.Fatalln("Read file fail!")
    }

    return n, err
}

// usage
accountInfo := make([]byte, 128)
readAccountFile(accountInfo)
fmt.Printf("content: %s\n", accountInfo)
