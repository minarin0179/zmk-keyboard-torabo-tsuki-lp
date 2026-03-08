# torabo_tsuki_lp ZMK キーボード

## プロジェクト概要

- ZMK ファームウェアを使用した分割キーボード
- 右手側にトラックボール（PAW3222）を搭載
- S / M / L の3サイズ対応（ZMK Studio でレイアウト切替可能）
- **現在使用中のレイアウト: M サイズ**

## 重要な知見

### `excluded-positions` はアクティブレイアウトの生の位置番号を使う

`zip_temp_layer` の `excluded-positions` プロパティに指定する位置番号は、
**ZMK Studio で選択中のレイアウトの matrix transform 上の生の位置番号**である。

`zmk_position_state_changed` イベントは `physical_layouts.c` の
`zmk_physical_layouts_kscan_process_msgq()` 内で
`zmk_matrix_transform_row_column_to_position(active->matrix_transform, row, col)`
を使って生成される。つまりアクティブなレイアウトの transform で変換した位置番号が使われる。

この位置番号は `keymap.c` が `selected_to_stock_map` でキーマップの canonical 位置に変換する前の値であるため、
**レイアウトを変えると `excluded-positions` の値も変える必要がある。**

### 各レイアウトにおけるマウスボタンキーの位置番号

Layer 1 でマウスボタンとして使用しているキー（J/K/L/;/'/,）の位置番号：

| キー | 物理位置 | S レイアウト | M レイアウト | L レイアウト |
|------|---------|------------|------------|------------|
| J    | RC(2,11) | 16 | 19 | 33 |
| K    | RC(2,10) | 17 | 20 | 34 |
| L    | RC(2,9)  | 18 | 21 | 35 |
| ;    | RC(2,8)  | 19 | 22 | 36 |
| '    | RC(2,7)  | なし | 23 | 37 |
| ,    | RC(3,10) | 29 | 34 | 48 |

### 現在の自動マウスレイヤー設定（M レイアウト用）

```dts
&zip_temp_layer {
    excluded-positions = <19 20 21 22 23 34>;
};

&pointing_listener {
    input-processors =
        <&zip_xy_transform (INPUT_TRANSFORM_X_INVERT | INPUT_TRANSFORM_Y_INVERT)>,
        <&zip_temp_layer 1 0>;
};
```

- タイムアウト `0` = 自動解除なし
- マウスボタンキーを押しても Layer 1 が解除されない
- それ以外のキーを押すと Layer 1 が解除される

## ファイル構成

| ファイル | 用途 |
|--------|------|
| `boards/shields/torabo_tsuki_lp/torabo_tsuki_lp.dtsi` | 共通ハードウェア定義（matrix transform、kscan など） |
| `boards/shields/torabo_tsuki_lp/torabo_tsuki_lp_layouts.dtsi` | 物理レイアウト定義・位置マップ |
| `boards/shields/torabo_tsuki_lp/torabo_tsuki_lp_left.overlay` | 左半分のオーバーレイ |
| `boards/shields/torabo_tsuki_lp/torabo_tsuki_lp_right.overlay` | 右半分のオーバーレイ（トラックボール設定含む） |
| `config/keymap.keymap` | キーマップ定義 |
