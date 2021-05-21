require "dry/system/container"
require "dry/system/components"

class NotifierContainer < Dry::System::Container
  use :logging
  use :monitoring
  use :env, inferrer: -> { ENV.fetch("RACK_ENV", :development).to_sym }
  configure do |config|
    # config.root = /root/app/dir
    config.auto_register = "lib"
  end
  load_paths!("lib", "system")
end
