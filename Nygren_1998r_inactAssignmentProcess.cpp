
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998r_inactAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998r_inactAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, k_rel_i );

  }

  Nygren_1998r_inactAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, k_rel_i );


  virtual void initialize()
  {
    Process::initialize();

    r_inact  = getVariableReference( "r_inact" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();

  }

  virtual void fire()
  {
    r_inact->setValue( 1 * (33.9600+339.600*(pow((Ca_i->getMolarConc()*1000)/((Ca_i->getMolarConc()*1000)+k_rel_i), 4.00000))) );

  }

 protected:

  Variable* r_inact;
  Variable* Ca_i;

  Real k_rel_i;

};

LIBECS_DM_INIT( Nygren_1998r_inactAssignmentProcess, Process );
