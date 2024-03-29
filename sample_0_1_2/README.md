# 0,1,2

最新の内容は下記 (TODO: READMEに同期する)  
https://forcia.esa.io/posts/20488   

## Challenge Name

0,1,2

## Problem Statement

`0`,`1`,`2` からなる、長さ`N` の数列`A` が与えられる。  
ここで、`1 <= i < j <= N` に対して、  
`f(i,j) = A_i * A_(i+1) * ... * A_j` とする。  
ただし、`1 <= i < j <= N` を満たさない `(i,j)` に対しては、`f(i,j) = -1` とする。  

このとき、以下をそれぞれ求めよ。  
- `f(i,j) = 0` となる、`(i,j)` の組の個数 `ans0`
- `f(i,j) = 1` となる、`(i,j)` の組の個数 `ans1`
- `f(i,j) = 2` となる、`(i,j)` の組の個数 `ans2`

## Input Format

```
N
A_1, A_2, ..., A_N
```

## Constraints

- `2 <= N <= 200000`
- `0 <= A_i <= 2`
- 入力はすべて整数

## Output Format

```
ans0 ans1 ans2
```
答えを空白区切りで出力せよ。  

## Sample Case

### Sample Case 1

Input
```
5
0 1 1 2 2
```

Output
```
4 1 2
```

`f(i,j) = 0` となる `(i,j)` は、`(1,2)`, `(1,3)`, `(1,4)`, `(1,5)` の`4`つである。  
`f(i,j) = 1` となる `(i,j)` は、`(2,3)` の`1`つである。  
`f(i,j) = 2` となる `(i,j)` は、`(2,4)`, `(3,4)` の`2`つである。  

### Sample Case 2

TODO
