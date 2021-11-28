## 1.ベースイメージのファイル類を./my-container/base-imageに突っ込む
docker export $(docker create alpine:latest) | tar -C ./my-docker/base-image -xvf -

## 2.突っこんだ./my-container/base-imageを./my-container/container-rootにコピー(そのうち実装)
cp -rf ./my-container/base-image/** ./my-container/container-root

## docker-composeを立ち上げて開発環境に入る
docker-compose up -d
docker-compose exec dev bash
cd ./src

## 開発環境でsrcをコンパイル
make

## プログラム実行
./my-container [any command] //ex. => ./my-container sh


