#!/usr/bin/env bash

# Display Sway window ids titles, switch to selection. Works with XWayland windows.
# Example use as a combi mode, combined with SSH:
#
# rofi -show combi -combi-modi "window:~/.config/rofi/sway_window_switch.sh,ssh" -modi combi

if [ "$@" ]
then
  id=$(echo $@ | cut -d ' ' -f 1)
  swaymsg -q "[con_id=$id]" focus
  exit 0;
else
  swaymsg -t get_tree | \
    jq -r '.nodes[].nodes[] | if .nodes then [recurse(.nodes[])] else [] end + .floating_nodes | .[] |  select(.nodes==[]) | ((.id | tostring) + " " + .name)'
fi
