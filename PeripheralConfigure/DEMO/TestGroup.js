(function($) {
	var dependenciesShow = true,
		observableChange = true;

	//return;
	///////////////////////////////////////////// Checkbox ////////////////////////////////////////////////////////////
	module("Group Tests for Checkbox Fields.");
	test("Dependencies Test1", function() {
		var testElement = S('#field1_sub0 div[name=group2_i2c0_wakeup_en]'),
			dependenciesElement = S('#field1_sub0 div[name=group1_UART1EnableINTCheckbox]');

		equal(dependenciesElement.length, 5, 'control UART1EnableINTCheckbox found.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control i2c0_wakeup_en hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].children[0].children[0].checked= true;
			dependenciesElement[1].children[0].children[0].checked= false;
			dependenciesElement[2].children[0].children[0].checked= false;
			dependenciesElement[3].children[0].children[0].checked= false;
			dependenciesElement[4].children[0].children[0].checked= false;
			dependenciesElement.change();
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control i2c0_wakeup_en shown.');
			});
		}
	});
	test("Dependencies Test2", function() {
		var testElement = S('#field1_sub0 input[name=GroupBPWM0Cap_BPWM0CapUnitTimeInterger]'),
			dependenciesElement = S('#field1_sub0 div[name=GroupBPWM0Cap0_UseBPWM0CH0ENCapBoolean]');

		equal(dependenciesElement.length, 1, 'control UseBPWM0CH0ENCapBoolean found.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control BPWM0CapUnitTimeInterger hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].children[0].children[0].checked= true;
			dependenciesElement.change();
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control BPWM0CapUnitTimeInterger shown.');
			});
		}
	});
	test("Observable Test", function() {
		var	testElement = S('#field1_sub0 select[name=group2_CRCModeSelect]'),
			observableElement = S('#field1_sub0 div[name=group1_UART1EnableINTCheckbox]');

		equal(observableElement.length, 5, 'control UART1EnableINTCheckbox found.');
		equal(testElement.length, 1, 'test control CRCModeSelect found.');
		ok(true, 'test control CRCModeSelect value ' + testElement.val());
		if (observableChange) {
			observableElement[0].children[0].children[0].checked= false;
			observableElement[1].children[0].children[0].checked= false;
			observableElement[2].children[0].children[0].checked= true;
			observableElement[3].children[0].children[0].checked= false;
			observableElement[4].children[0].children[0].checked= false;
			observableElement.change();
			S.wait(500, function() {
				equal(testElement.val(), 'CRC_16', 'test control CRCModeSelect changed value to CRC_16 correctly.');
			});
		}
	});
}(jQuery) );
