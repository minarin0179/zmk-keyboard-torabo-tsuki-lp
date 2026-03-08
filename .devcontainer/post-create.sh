#!/usr/bin/env bash
set -eu

WEST_WORKSPACE="/workspaces/zmk"
CONFIG_REPO="/workspaces/zmk-keyboard-torabo-tsuki-lp"

echo "=== Setting up ZMK west workspace ==="

mkdir -p "${WEST_WORKSPACE}"

# west expects this repo at <workspace>/config/ (manifest self.path: config)
ln -sfn "${CONFIG_REPO}" "${WEST_WORKSPACE}/config"

if [ ! -d "${CONFIG_REPO}/.west" ]; then
    echo "--- Running west init ---"
    cd "${WEST_WORKSPACE}"
    west init -l config/config
fi

echo "--- Running west update ---"
cd "${CONFIG_REPO}"
west update

echo ""
echo "=== West workspace ready ==="
echo ""
echo "Build example:"
echo "  cd ${CONFIG_REPO}"
echo "  west build -s zmk/app -b bmp_boost -d build/left_central \\"
echo "    -S studio-rpc-usb-uart -S split-central -S input-trackball -S input-listener \\"
echo "    -- -DSHIELD=torabo_tsuki_lp_left \\"
echo "       -DZMK_CONFIG=${CONFIG_REPO}/config \\"
echo "       -DZMK_EXTRA_MODULES=${CONFIG_REPO}"
