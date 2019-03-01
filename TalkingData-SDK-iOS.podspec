Pod::Spec.new do |s|

  s.name         = 'TalkingData-SDK-iOS'
  s.version      = '4.0.30'
  s.summary      = 'Ricebook used SDK for iOS'

  s.homepage     = 'https://github.com/ricebook/iOS-lib-AdTracking'

  s.license      = 'MIT'
  s.author       = { 'Ricebook' => 'support@ricebook.com' }

  s.platform     = :ios, '8.0'
  s.source       = { :git => 'https://github.com/ricebook/iOS-lib-AdTracking.git' }

  s.source_files  = 'Sources/lib/*.h'
  s.vendored_library = 'Sources/lib/*.a'
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.frameworks = 'Security', 'CoreTelephony', 'AdSupport', 'SystemConfiguration', 'CoreMotion'

  s.library = "z", "c++"

end