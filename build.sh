#!/usr/bin/env bash
set -euo pipefail

WORKSPACE="$(cd "$(dirname "$0")" && pwd)"
ZMK_APP="$WORKSPACE/zmk/app"
ZEPHYR_DIR="$WORKSPACE/zephyr/share/zephyr-package/cmake"

COMMON_ARGS=(
    -DZephyr_DIR="$ZEPHYR_DIR"
    -DBOARD_ROOT="$WORKSPACE"
    -DZMK_CONFIG="$WORKSPACE/config"
    -DSNIPPET_ROOT="$WORKSPACE"
)

build() {
    local artifact="$1"
    local board="$2"
    local shield="$3"
    local snippet="$4"
    local pristine="${PRISTINE:-}"

    echo "==> Building: $artifact"
    local args=(-b "$board" -d "$WORKSPACE/build/$artifact" "$ZMK_APP")
    [[ -n "$pristine" ]] && args+=(-p always)
    args+=(-- -DSHIELD="$shield")
    [[ -n "$snippet" ]] && args+=("-DSNIPPET=$snippet")
    args+=("${COMMON_ARGS[@]}")

    west build "${args[@]}"

    local uf2="$WORKSPACE/build/$artifact/zephyr/zmk.uf2"
    mkdir -p "$WORKSPACE/dist"
    cp "$uf2" "$WORKSPACE/dist/${artifact}.uf2"
    echo "==> Done: dist/${artifact}.uf2"
}

usage() {
    cat <<EOF
Usage: $0 [OPTIONS] <target> [target ...]

Targets:
  left_central                   左手側 central (トラックボールが左)
  right_peripheral               右手側 peripheral
  left_peripheral                左手側 peripheral
  right_central                  右手側 central (トラックボールが右)
  double_ball_left_peripheral    ダブルボール左 peripheral
  double_ball_right_central      ダブルボール右 central
  settings_reset                 設定リセット
  all                            上記すべて

Options:
  -p, --pristine    クリーンビルド
  -h, --help        このヘルプを表示
EOF
}

TARGETS=()
for arg in "$@"; do
    case "$arg" in
        -p|--pristine) PRISTINE=1 ;;
        -h|--help) usage; exit 0 ;;
        *) TARGETS+=("$arg") ;;
    esac
done

if [[ ${#TARGETS[@]} -eq 0 ]]; then
    usage
    exit 1
fi

for target in "${TARGETS[@]}"; do
    case "$target" in
        left_central)
            build torabo_tsuki_lp_left_central bmp_boost torabo_tsuki_lp_left \
                "studio-rpc-usb-uart split-central input-trackball input-listener" ;;
        right_peripheral)
            build torabo_tsuki_lp_right_peripheral bmp_boost torabo_tsuki_lp_right \
                "studio-rpc-usb-uart" ;;
        left_peripheral)
            build torabo_tsuki_lp_left_peripheral bmp_boost torabo_tsuki_lp_left \
                "studio-rpc-usb-uart" ;;
        right_central)
            build torabo_tsuki_lp_right_central bmp_boost torabo_tsuki_lp_right \
                "studio-rpc-usb-uart split-central input-trackball input-listener" ;;
        double_ball_left_peripheral)
            build torabo_tsuki_lp_double_ball_left_peripheral bmp_boost torabo_tsuki_lp_left \
                "studio-rpc-usb-uart input-trackball input-split" ;;
        double_ball_right_central)
            build torabo_tsuki_lp_double_ball_right_central bmp_boost torabo_tsuki_lp_right \
                "studio-rpc-usb-uart split-central input-trackball input-listener input-split-listener" ;;
        settings_reset)
            build settings_reset bmp_boost settings_reset "" ;;
        all)
            build torabo_tsuki_lp_left_central bmp_boost torabo_tsuki_lp_left \
                "studio-rpc-usb-uart split-central input-trackball input-listener"
            build torabo_tsuki_lp_right_peripheral bmp_boost torabo_tsuki_lp_right \
                "studio-rpc-usb-uart"
            build torabo_tsuki_lp_left_peripheral bmp_boost torabo_tsuki_lp_left \
                "studio-rpc-usb-uart"
            build torabo_tsuki_lp_right_central bmp_boost torabo_tsuki_lp_right \
                "studio-rpc-usb-uart split-central input-trackball input-listener"
            build torabo_tsuki_lp_double_ball_left_peripheral bmp_boost torabo_tsuki_lp_left \
                "studio-rpc-usb-uart input-trackball input-split"
            build torabo_tsuki_lp_double_ball_right_central bmp_boost torabo_tsuki_lp_right \
                "studio-rpc-usb-uart split-central input-trackball input-listener input-split-listener"
            build settings_reset bmp_boost settings_reset ""
            ;;
        *)
            echo "Error: unknown target '$target'" >&2
            usage
            exit 1 ;;
    esac
done
