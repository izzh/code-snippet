package featureTest

import (
    "errors"
)

// 自定义错误类型
var errDivByZero = errors.New("division by zero")

// 实现error接口
type needData struct {
    x, y int
}

func (* needData) Error() string {
    return "division by zero"
}

func Div(x, y int) (int, error) {
    if y == 0 {
        return 0, errDivByZero
    }

    return x/y, nil
}

func Div2(x, y int) (int, error) {
    if y == 0 {
        return 0, &needData{x, y}
    }

    return x/y, nil
}
