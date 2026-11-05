Pod::Spec.new do |s|
  s.name             = 'JMapiOSSDK'
s.version='6.0.0'
  s.summary          = 'The Jibestream JMap 4.0 iOS SDK.'

  s.description      = 'This CocoaPod provides the release version for the Jibestream iOS SDK.'

  s.homepage         = 'http://www.jibestream.com/'
  s.author           = { 'Louie' => 'lyuen@jibestream.com' }
  s.source           = { :git => 'https://github.com/Jibestream/JMap-iOS-SDK-Pod.git', :tag => "#{s.version}" }

  s.platform = :ios, '15.0'
#  s.source_files = 'JMapiOSSDK4.0/Classes/*.{h,m}'
  s.vendored_frameworks = 'JMapiOSSDK4.0/Frameworks/*.xcframework'

end
