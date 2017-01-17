#
# Be sure to run `pod lib lint JMapiOSSDK4.0.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'JMapiOSSDK4.0'
  s.version          = '1.0.0'
  s.summary          = 'The Jibestream JMap 4.0 iOS SDK.'

  s.description      = 'This CocoaPod provides the release version for the Jibestream iOS SDK.'

  s.homepage         = 'http://www.jibestream.com/'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Louie' => 'lyuen@jibestream.com' }
  s.source           = { :git => 'https://github.com/Jibestream/JMapControllerKit-iOS.git', :tag => "#{s.version}" }

  s.ios.deployment_target = '9.0'
  s.platform = :ios, '9.0'
  s.source_files = 'JMapiOSSDK4.0/Classes/*.{h,m}'
  s.vendored_frameworks = 'JMapiOSSDK4.0/Frameworks/*.framework'

end
