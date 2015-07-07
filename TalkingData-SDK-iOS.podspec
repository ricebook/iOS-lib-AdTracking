Pod::Spec.new do |s|

  s.name         = 'TalkingData-SDK-iOS'
  s.version      = '0.0.1'
  s.summary      = 'ENJOY used SDK for iOS'

  s.homepage     = 'https://github.com/ricebook/iOS-lib-AdTracking'

  s.license      = 'MIT'
  s.author       = { 'Ricebook' => 'support@ricebook.com' }

  s.platform     = :ios, '5.1.1'
  s.source       = { :git => 'https://github.com/ricebook/iOS-lib-AdTracking.git' }


  s.source_files  = 'lib/*.h'
  s.vendored_library = 'lib/*.a'


  s.frameworks = 'Security', 'CoreTelephony', 'AdSupport', 'SystemConfiguration'

  s.xcconfig = { 'OTHER_LDFLAGS' => '/usr/lib/libz.dylib' }

end