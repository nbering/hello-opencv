# Hello OpenCV

## Dependencies

Just tinkering with the Open Computer Vision (OpenCV) library.

To install the library depencies on MacOS I used Homebrew.

```bash
brew install homebrew/science/opencv3 \
    --with-contrib \
    --with-ffmpeg \
    --with-gstreamer \
    --with-qt5
```

Homebrew gives some instructions for linking to the keg-only package,
I won't cover that here now because it depends a lot on what is used
for build tooling.

## Goal

Just tinkering in C++ with OpenCV. Primarily trying to build something
like [Wesley the Augmented Whiteboard](https://github.com/martinhj/wesleywhiteboard).
I may try to get this working on a Raspberry Pi so that I can use it as
a dedicated augmented whiteboard appliance in my office. Undecided at
this time.

## Resources

- [OpenCV v3.2.0 Documentation](http://docs.opencv.org/3.2.0/index.html)
- [Homebrew Package](https://github.com/Homebrew/homebrew-science/blob/master/opencv3.rb)
- [C++ Projects in Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp)

## License

Except as marked otherwise in file headers, code in this repository is
licensed under the MIT License. See [LICENSE](./LICENSE).

OpenCV itself is licensed under a BSD 3-clause license. See
[OpenCV License Page](http://opencv.org/license.html).
