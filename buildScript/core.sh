#!/bin/sh
########################################################################
#
#  core.sh
#
#  Created by wuyj on 14/9/18.
#  Copyright (c) 2018 asiainfo. All rights reserved.
#
########################################################################

# 创建相关变量
# 工程的xcodeproj目录
projectDir=..
# ipa包的保存位置
# 当前sh路径
build_shPath=${PWD}
ipaSaveDir=${build_shPath}/ipa

configurationName="Release"

# 当前编译的用的mobileprovision文件
mobileprovision="${build_shPath}/${code_sign_profile}"

projectBuild="${projectDir}/build"
distributionDir="${projectBuild}/${configurationName}-iphoneos"
projectFile="${targetName}.xcodeproj"


# 清理上次编译的临时文件
# xcodebuild clean -configuration "$configurationName" -sdk iphoneos -project "$projectDir/$projectFile" -target "$targetName"

# 删除编译文件夹
rm -rf "$projectBuild"

#编译工程 -xcconfig "$build_shPath/Config.xcconfig"
xcodebuild  -project "$projectDir/$projectFile" -target "$targetName" -configuration "$configurationName" -sdk iphoneos build

if [ $? != 0 ]
then
exit 1
fi

# 删除上次的编译版本
if [ -d "${ipaSaveDir}" ]
then
rm -rf "${ipaSaveDir}"
fi
mkdir -p "${ipaSaveDir}"

xcrun -sdk iphoneos ./PackageApplication -v "$distributionDir/${targetName}.app" -o "${ipaSaveDir}/${targetName}.ipa" --embed "${mobileprovision}" --sign "${code_sign_identity}"

# 删除编译文件夹
rm -r "${projectBuild}"

