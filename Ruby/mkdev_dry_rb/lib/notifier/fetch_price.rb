require 'http'

module Notifier
  class FetchPrice
    def call(ticker)
      HTTP.get(url(ticker)).yield_self do |response|
        parsed_response = JSON.parse(response)
        open_price = parsed_response.fetch("Time Series (Daily)").fetch("2021-05-05").fetch("1. open")
        BigDecimal(open_price, 2)
      end
    end

    private

    def url(ticker)
      "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=#{ticker}&apikey=demo"
    end
  end
end
