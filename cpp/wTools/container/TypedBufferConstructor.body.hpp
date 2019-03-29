
// --
// constructor
// --

Template
inline Self::SelfConstructor()
{
  self._begin = NULL;
  self._end = NULL;
  self._length = 0;
}

//

Template
inline Self::SelfConstructor( Self::Element* data, Self::SizeType length )
{
  self.use( data,length );
}

//

Template
inline Self::SelfConstructor( Self::Element* begin, Self::Element* end )
{
  self.use( begin,end );
}

//

Template
inline Self::SelfConstructor( const Self::Class& src )
{
  self.use( src );
}

//

Template
inline
typename Self::Class&
Self::useDataOfSize( void* data, Self::SizeType size )
{
  assert_M( size % sizeof( Self::Element ) == 0 );

  size_t length = size / sizeof( Self::Element );
  self._begin = (Self::Element*)data;
  self._end = (Self::Element*)( ((char*)data) + length );
  self._length = length;
  return self;
}

//

Template
inline
typename Self::Class&
Self::use( Self::Element* data, Self::SizeType length )
{
  self._begin = data;
  self._end = data + length;
  self._length = length;
  return self;
}

//

Template
inline
typename Self::Class&
Self::use( Self::Element* begin, Self::Element* end )
{
  self._begin = begin;
  self._end = end;
  self._length = ( end-begin );
  return self;
}

//

Template
inline
typename Self::Class&
Self::use( const Self::Class& src )
{
  self._begin = src._begin;
  self._end = src._end;
  self._length = src._length;
  return self;
}

//

Template
inline
typename Self::Class&
Self::clone()
{
  auto& result = new Self( self );
  return result;
}

//

Template
inline
typename Self::Class&
Self::operator=( const Self::Class& src )
{
  self.use( src );
  return self;
}
