
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998f_CaAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998f_CaAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, k_Ca );

  }

  Nygren_1998f_CaAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, k_Ca );


  virtual void initialize()
  {
    Process::initialize();

    f_Ca  = getVariableReference( "f_Ca" ).getVariable();
    Ca_d  = getVariableReference( "Ca_d" ).getVariable();

  }

  virtual void fire()
  {
    f_Ca->setValue( 1 * ((Ca_d->getMolarConc()*1000)/((Ca_d->getMolarConc()*1000)+k_Ca)) );

  }

 protected:

  Variable* f_Ca;
  Variable* Ca_d;

  Real k_Ca;

};

LIBECS_DM_INIT( Nygren_1998f_CaAssignmentProcess, Process );
