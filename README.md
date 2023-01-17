# yurufuwa_onsite_04
:yatteikuzo:

# テストケースの作り方
以下 Linux系の作業環境を想定しています
ほぼ以下の抜粋ですが必要に応じて参照ください    
http://web.archive.org/web/20191217153910/https://beet-aizu.hatenablog.com/entry/2018/08/20/203706

## rime インストール

rimeが必要なので (入っていなければ) インストールします  
pythonとpipが入っている必要がありますが、下記でインストールできます。 

``` 
pip install git+https://github.com/icpc-jag/rime
```

## 問題ディレクトリ作成

当ディレクトリ (`yurufuwa_onsite_04`)直下で、下記を実行します。  
```
rime add . problem <problem_dir_name>
```

ここで、`<problem_dir_name>` が作られるディレクトリ名となりますが、ここは問題名で良いです。  

上記を実行するとPROBLEMファイルが(デフォルト)vimで開きます。  
`Your Problem Name` のところを変更するのと、`time_limit` をいじることになるかと思います。  
HackerRankの場合 time_limit は言語によって変動するのであんまり意味ないですが、ひとまずcppでの想定時間を書いておくと良いと思います。  
(特に想定計算量がきわどくなければ2秒を推奨します)  

`reference_solution` のところには想定解を指定できるのですが、想定解ディレクトリを作ったあとで指定しましょう。  


## 解答ディレクトリの作成

先ほどの問題ディレクトリ下で、下記を実行します。  
```
rime add . solution <solution_dir_name>
```

`<solution_dir_name>` が作られるディレクトリ名となりますが、命名規則は `{名前}_{言語}_{想定結果}` としましょう。  
例えば、サンプルでは `prd_py_AC` や `prd_py_TLE` を作ってあります  
(prd の部分は作業者がわかればなんでも良いです)  

上記コマンドを実行するとSOLUTIONファイルが(デフォルト)vimで開きます。  
c++ の場合 `cxx_solution` の行を、  
python などスクリプト言語の場合 `script_solution` の行をコメントインしましょう。  
srcには解答プログラム名を指定できますが、基本的には `main.cpp` などのままで良いかと思います。  

## 解答プログラムの作成

先ほどの解答用ディレクトリの下にファイルを作成します。  
プログラム名は先ほどのsrcに指定した `main.cpp` などとします。  
こちらに想定結果となるプログラムを実装します。  

なお、python などスクリプト言語の場合は1行目にshebangが必要です。  
pythonの場合下記を1行目に書きましょう。  
```
#!/usr/bin/env python3
```

## テスト用ディレクトリの作成

問題ディレクトリの直下で、下記を指定します。  
```
rime add . testset tests
```

すると、`tests` という名前のディレクトリが作られ、TESTSETファイルが開きます。  
generator と validator の設定をします。  
必要な行をコメントインしてください。  
generatorは テストケースの生成をします。言語は任意です。  
validatorは テストケースが制約通りに入力されるかの検証を行います。言語は**c++ 必須**です。(`testlib` を使うと末尾の空白などを検証できるらしい)  

## generator / validator の作成

generator と validator を作成します。  

下記 beetさんのサンプルや    
http://web.archive.org/web/20191217153910/https://beet-aizu.hatenablog.com/entry/2018/08/20/203706  

第2回ゆるふわのアーカイブを参考にしてください    
https://github.com/matsu7874/contest_20190914/tree/master/13_fuzzy_search_queries/tests

(第3回のアーカイブどこかにある？)  

簡易的なものであれば `sample_0_1_2` にもサンプルがあります。  

テストケース作成観点などは以下が参考になったりします。  
https://qiita.com/e869120/items/45a0132263094b83fc44

## テストの実行

問題ディレクトリ下で  
```
rime test {解答ディレクトリ名}
```
で、指定した解答ディレクトリがテストされます。  
解答ディレクトリを省略すると、全ての問題ディレクトリに対してテストされます。  

`rime test` は気軽に行えるので、想定通りの結果になっているかを常に確認しましょう。  

## テストケースの書き出し

問題ディレクトリで
```
rime pack
```

を実行すると、rime-out ディレクトリの下に `hacker_rank/hacker_rank.zip` が作られるように設定してあります。  
こちらのzipを HackerRankに登録します。(方法は別途紹介)  
