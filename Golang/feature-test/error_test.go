package featureTest

import (
    "testing"
)

func Test_Div(t *testing.T) {

    r, err := Div(1024, 4)
    if err == nil && r == 256 {
        t.Log("testing pass!")
    } else {
        t.Error("testing fail!")
    }

    r, err = Div(1024, 0)
    // 通过错误变量而非错误内容判断
    if err == errDivByZero {
        t.Log(err)
        t.Log("testing pass!")
    } else {
        t.Error("testing fail!")
    }

    r, err = Div2(1024, 0)
    if err != nil {
        t.Log(err)
        t.Log("testing pass!")
    } else {
        t.Error("testing fail!")
    }
}
