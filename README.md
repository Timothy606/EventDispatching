# EventDispatching
C++ Event Dispatching Library (Header Only)

Compact C++ Header only Event library that allows Objects to register to Events with member functions

As this is a template library it allows for practially any class to register a member function to the event so long as that member function follows the correct argument list

Code Example:
```
class ClassType
{
public:

  Function();
  
}
EventInstance.Register<ClassType>(ClassInstance, &ClassType::Function);
EventInstance.Dispatch();
```
## Dependencies

- std::vector

std::vector could be replaced by any Container class of your choice as long as it can be iterated over

## License

The EventDispatching library falls under the standard MIT License
