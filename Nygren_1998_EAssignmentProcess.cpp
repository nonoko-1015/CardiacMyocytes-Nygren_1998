
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_EAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_EAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, R );
    PROPERTYSLOT_SET_GET( Real, T );
    PROPERTYSLOT_SET_GET( Real, F );
    PROPERTYSLOT_SET_GET( Real, z );

  }

  Nygren_1998_EAssignmentProcess()
    :R( 8314.0 ), T( 306.15 ), F( 96487.0 ), z( 1.0 )
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, R );
  SIMPLE_SET_GET_METHOD( Real, T );
  SIMPLE_SET_GET_METHOD( Real, F );
  SIMPLE_SET_GET_METHOD( Real, z );


  virtual void initialize()
  {
    Process::initialize();

    E  = getVariableReference( "E" ).getVariable();
    o  = getVariableReference( "o" ).getVariable();
    i  = getVariableReference( "i" ).getVariable();

    RT_zF = ( R * T )/( z * F );
  }

  virtual void fire()
  {
    E->setValue( RT_zF * log( o->getMolarConc() / i->getMolarConc()));

  }

 protected:

  Variable* E;
  Variable* o;
  Variable* i;

  Real R;
  Real T;
  Real F;
  Real z;

  Real RT_zF;
};

LIBECS_DM_INIT( Nygren_1998_EAssignmentProcess, Process );
