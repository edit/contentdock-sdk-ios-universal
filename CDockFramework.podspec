Pod::Spec.new do |s|
  s.name         = 'CDockFramework'
  s.version      = '1.0.1'
  s.license       = { :type => 'MIT' }
  s.homepage      = 'https://github.com/edit/contentdock-sdk-ios-universal'
  s.authors       = { 'Michael Schild' => 'michael.schild@edit.de' }
  s.summary       = 'Universal SDK for contentDock.com'
  s.source        = { :git => 'https://github.com/edit/contentdock-sdk-ios-universal.git', :tag => s.version }
  s.vendored_frameworks = 'CDockFramework.xcframework'
  s.documentation_url ='https://www.contentdock.com/en/documentation/sdk-ios'
  s.swift_version = '5.0'
  s.ios.deployment_target  = '13.0'
end
