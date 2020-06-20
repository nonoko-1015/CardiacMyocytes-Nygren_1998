
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_diAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_diAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, tau_di );
    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998i_diAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, tau_di );
  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    i_di  = getVariableReference( "i_di" ).getVariable();
    Ca_d  = getVariableReference( "Ca_d" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();

  }

  virtual void fire()
  {
    i_di->setValue( 1 * ((((Ca_d->getMolarConc()*1000)-(Ca_i->getMolarConc()*1000))*2.00000*F* getSuperSystem()->getSize() * 1.0e9)/tau_di) );

  }

 protected:

  Variable* i_di;
  Variable* Ca_d;
  Variable* Ca_i;

  Real tau_di;
  Real F;

};

LIBECS_DM_INIT( Nygren_1998i_diAssignmentProcess, Process );
