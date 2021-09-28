[![Issues](https://img.shields.io/github/issues/lbonn/rofi.svg)](https://github.com/lbonn/rofi/issues)
[![Forks](https://img.shields.io/github/forks/lbonn/rofi.svg)](https://github.com/lbonn/rofi/network)
[![Stars](https://img.shields.io/github/stars/lbonn/rofi.svg)](https://github.com/lbonn/rofi/stargazers)
[![Downloads](https://img.shields.io/github/downloads/lbonn/rofi/total.svg)](https://github.com/lbonn/rofi/releases)
[![Packages](https://repology.org/badge/tiny-repos/rofi-wayland.svg)](https://repology.org/metapackage/rofi-wayland/versions)

# A window switcher, Application launcher and dmenu replacement

**This is a fork of [Rofi](https://github.com/davatorium/rofi) with added support for Wayland via the [layer shell protocol](https://github.com/swaywm/wlr-protocols).**
**For more information, see the [Wayland support section](#wayland-support)**

**Rofi** started as a clone of simpleswitcher, written by [Sean Pringle](http://github.com/seanpringle/simpleswitcher) - a
popup window switcher roughly based on [superswitcher](http://code.google.com/p/superswitcher/).
Simpleswitcher laid the foundations, and therefore Sean Pringle deserves most of the credit for this tool. **Rofi**
(renamed, as it lost the *simple* property) has been extended with extra features, like an application launcher and
ssh-launcher, and can act as a drop-in dmenu replacement, making it a very versatile tool.

**Rofi**, like dmenu, will provide the user with a textual list of options where one or more can be selected.
This can either be running an application, selecting a window, or options provided by an external script.

Its main features are:

*   Fully configurable keyboard navigation
*   Type to filter
    *   Tokenized: type any word in any order to filter
    *   Case insensitive (togglable)
    *   Support for fuzzy-, regex-, and glob matching
*   UTF-8 enabled
    *   UTF-8-aware string collating
    *   International keyboard support (\`e -> è)
*   RTL language support
*   Cairo drawing and Pango font rendering
*   Built-in modes:
    *   Window switcher mode
        *   EWMH compatible WM
    *   Application launcher
    *   Desktop file application launcher
    *   SSH launcher mode
    *   Combi mode, allowing several modes to be merged into one list
*   History-based ordering — last 25 choices are ordered on top based on use (optional)
*   Levenshtein distance or fzf like sorting of matches (optional)
*   Drop-in dmenu replacement
    *   Many added improvements
*   Easily extensible using scripts and plugins
*   Advanced Theming

**Rofi** has several built-in modi implementing common use cases and can be extended by scripts (either called from
**Rofi** or calling **Rofi**) or plugins.

Below is a list of the different modi:

* **run**: launch applications from $PATH, with option to launch in terminal.
* **drun**: launch applications based on desktop files. It tries to be compliant to the XDG standard.
* **window**: Switch between windows on an EWMH compatible window manager.
* **ssh**: Connect to a remote host via ssh.
* **file-browser**: A basic file-browser for opening files.
* **keys**: list internal keybindings.
* **script**: Write (limited) custom mode using simple scripts.
* **combi**: Combine multiple modi into one.

**Rofi** is known to work on Linux and BSD.

# Wayland support

To enable Wayland support, build the project with meson and make sure the wayland feature is enabled (it is by default).

```
meson build -Dwayland=enabled
```

The rest of the installation process is unchanged (see [Installation](#Installation)).

**Rofi** can be invoked with the same CLI and configuration and can be forced to use X11 mode with the x11 flag:

    rofi -x11 ...

This port to layer shell is not yet in a stable state, so expect to encounter some rough edges. That said, the core of Rofi's functionalities is present.

Notable omissions:

  * native window mode when running under Wayland. Recommended solution: https://github.com/lbonn/i3-focus-last#menu-mode
  * `-normal-window` flag in Wayland mode. Upstream rofi considers it a toy/deprecated feature AFAIK
  * selecting which monitor to run rofi on in Wayland mode, rofi only shows up on the currently focused monitor
  * advanced window location options such as x-offset and y-offset. It would probably be quite difficult with layer shell
  * some X11-specific options like `-dpi` or fake transparency

If you find something does not work and is not listed here, please open a PR.

I do not intend to make releases from this fork at the moment, but will simply try to keep it regularly in sync with the develop branch upstream.

# Screenshots

![screenshot](https://raw.githubusercontent.com/davatorium/rofi/next/releasenotes/1.6.0/icons.png)
![screenshot2](https://raw.githubusercontent.com/davatorium/rofi/next/releasenotes/1.6.0/icons2.png)
![default](https://raw.githubusercontent.com/davatorium/rofi/next/releasenotes/1.4.0/rofi-no-fzf.png)

# Manpage

For more up to date information, please see the manpages:

 * Manpages:
     * [rofi](doc/rofi.1.markdown)
     * [rofi-theme](doc/rofi-theme.5.markdown)
     * [rofi-script](doc/rofi-script.5.markdown)
     * [rofi-theme-selector](doc/rofi-theme-selector.1.markdown)
 * Discussion places:
     * [Reddit](https://reddit.com/r/qtools/)
     * [GitHub Discussions](https://github.com/davatorium/rofi/discussions)
     * IRC (#rofi on irc.libera.chat)
 * [wiki](https://github.com/davatorium/rofi/wiki) (Currently unmaintained).

# Installation

Please see the [installation guide](INSTALL.md) for instructions on how to
install **Rofi**.

# What is rofi not?

Rofi is not:

*   A UI toolkit.
*   A library to be used in other applications.
*   An application that can support every possible use-case. It tries to be generic enough to be usable by everybody.
    * Specific functionality can be added using scripts or plugins, many exists.
*   Just a dmenu replacement. The dmenu functionality is a nice 'extra' to **rofi**, not its main purpose.
