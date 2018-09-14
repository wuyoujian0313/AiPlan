

一、配置步骤
1、配置好工程的证书；
2、从证书的获取：Team字段
3、对应修改build.sh里的3个字段的值
4、把证书mobileprovision文件拷贝到当前目录



二、常见文件：
1、错误：xcode-select: error: tool 'xcodebuild' requires Xcode, but active developer directory '/Library/Developer/CommandLineTools' is a command line tools instance
在执行自动化打包的时候报错，检查发现是Xcode的路径被改了

解决：
在终端输入
sudo xcode-select -switch /Applications/Xcode8.app/Contents/Developer
重置Xcode路径，再执行打包命令，success。。。

2、错误：xcrun: error: unable to find utility "PackageApplication", not a developer tool or in PATH
解决:
新版本Xcode没有这个工具了，请下载PackageApplication。放置到：
/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin
或者自定义目录，脚本xcrun从这个目录加载这个工具

3、错误：--resource-rules has been deprecated in mac os x >= 10.10
解决：
修改工具PackageApplication，这一个脚本用编辑工具打开：
把 my @codesign_args = ("/usr/bin/codesign", "--force", "--preserve-metadata=identifier,entitlements,resource-rules",
                  "--sign", $opt{sign},
                  "--resource-rules=$destApp/ResourceRules.plist");

改成：my @codesign_args = ("/usr/bin/codesign", "--force", "--preserve-metadata=identifier,entitlements",
                  "--sign", $opt{sign});
