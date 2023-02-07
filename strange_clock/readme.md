

# strange clock

## Challenge Name

Strange clock

## Problem Statement

太郎君が持っている時計には`N`本の針があります。
$i(1 \leq i \leq N)$本目の針は$1$本目の針が一周する間に$A_i$周します。

また、全ての針は時計回りに等速で動き続け$A_i$は相異なります。
太郎君は全ての針が揃った状態から$1$本目の針が一周する間に$2$本以上の針が重なる瞬間がいくつあるのか気になりました。太郎君の代わりにこれを求めてください。

ただし、最初に針が揃っている瞬間はカウントせず、最後に針が揃う瞬間はカウントするものとします。

## Input Format

```
N
A_1, A_2, ..., A_N
```

## Constraints

- `1 <= N <= 200000`
- `1 <= A_i <= 200000`
- `A_1 = 1`
- 入力はすべて整数
- 入力はすべて相異なる

## Output Format

```
ans
```
答えを空白区切りで出力せよ。  

## Sample Case

### Sample Case 1

Input
```
3
1 2 3
```

Output
```
2
```
  

### Sample Case 2

Input
```
3
1 720 43200
```

Output
```
86396
```