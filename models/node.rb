require 'pry'
class C
  def self.typedef hash={}
    class_variable_set(:@@elements, hash)
    @@elements = hash
    define_method(:definition) do
      r = "typedef struct #{self.class} {\n"
      hash.each do |name, args|
        type = args[:type]
        l = type.to_s.chars.first
        data_type = (l == l.upcase) ? "struct #{type.to_s}" : "#{type.to_s}"
        r+=" #{data_type}#{" *" if args[:p]} #{name.to_s};\n"
      end
      r+="} #{self.class};\n"
    end
  end
  def self.constructor params={}
    definition_proc = Proc.new do |this|
      definition = "#{this.class} * new_#{this.class.to_s.downcase}("
      params.each do |name, args|
        type = @@elements[name][:type]
        p = @@elements[name][:p]
        definition+="#{type}#{" *" if p} #{name.to_s}, "
      end
      definition = definition[0..-3]+")"
    end
    define_method(:declare_new) do
      "extend #{definition_proc.call(self)};\n"
    end
    define_method(:define_new) do
      r = "#{definition_proc.call(self)}\n"
      r+="{\n"
      r+=" #{self.class} * new = malloc(sizeof(#{self.class}));\n"
      r+="  if(!new)\n"
      r+="    fprintf(stderr, \"Failed to allocate memory for #{self.class}\\n\");\n"
      @@elements.each do |name, args|
        r+="  new->#{name.to_s} = #{name.to_s};\n"
      end
      r+="  return new;\n"
      r+="}"
    end
  end
end

class Node < C
  typedef(:data => {:type => :int}, 
          :next_node => {:type => :Node, :p => true})
  constructor(:data => {:set => true},
              :next_node => {:set => false})
end

n = Node.new
puts n.definition
puts n.declare_new
puts n.define_new
