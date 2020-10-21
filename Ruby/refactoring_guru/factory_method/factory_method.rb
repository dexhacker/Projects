# frozen_string_literal: true

# @abstract
class Creator
  # @abstract
  def factory_method
    raise NotImplementedError, "#{self.class} has not implemented method '#{__method__}'"
  end

  # @return [String]
  def some_operation
    product = factory_method

    result = "Creator: The same creator's code has just worked with #{product.operation}"

    result
  end
end

class ConcreteCreator1 < Creator
  # @return [ConcreteProduct1]
  def factory_method
    ConcreteProduct1.new
  end
end

class ConcreteCreator2 < Creator
  # @return [ConcreteProduct2]
  def factory_method
    ConcreteProduct2.new
  end
end

# @abstract
class Product
  # return [String]
  def operation
    raise NotImplementedError, "#{self.class} has not implemented method '#{__method__}'"
  end
end

class ConcreteProduct1 < Product
  # @return [String]
  def operation
    '{Result of the ConcreteProduct1}'
  end
end

class ConcreteProduct2 < Product
  # @return [String]
  def operation
    '{Result of the ConcreteProduct2}'
  end
end

# @param [Creator] creator
def client_code(creator)
  puts "Client: I'm not aware of the creator's class, but it still works."
  puts creator.some_operation
end

puts 'App: Launched with the ConcreteCreator1.'
client_code(ConcreteCreator1.new)
puts
puts

puts 'App: Launched with the ConcreteCreator2.'
client_code(ConcreteCreator2.new)
