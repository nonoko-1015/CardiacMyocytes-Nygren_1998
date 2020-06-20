
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_trAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_trAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, tau_tr );
    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998i_trAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, tau_tr );
  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    i_tr  = getVariableReference( "i_tr" ).getVariable();
    Ca_up  = getVariableReference( "Ca_up" ).getVariable();
    Ca_rel  = getVariableReference( "Ca_rel" ).getVariable();

  }

  virtual void fire()
  {
    i_tr->setValue( 1 * ((((Ca_up->getMolarConc()*1000)-(Ca_rel->getMolarConc()*1000))*2.00000*F*getSuperSystem()->getSize()*1.0e9)/tau_tr) );

  }

 protected:

  Variable* i_tr;
  Variable* Ca_up;
  Variable* Ca_rel;

  Real tau_tr;
  Real F;

};

LIBECS_DM_INIT( Nygren_1998i_trAssignmentProcess, Process );
