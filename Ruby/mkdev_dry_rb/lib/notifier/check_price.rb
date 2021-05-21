module Notifier
  class CheckPrice
    def call(price, boundary)
      NotifierContainer.logger.info("Price is #{price.to_f}, time to buy") if price > boundary
    end
  end
end
