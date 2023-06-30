(function($) {
	var observableChange = true;

	//return;
	///////////////////////////////////////////// Select ////////////////////////////////////////////////////////////
	module("Observable Tests for Select Fields.");
	test("Single Test", function() {
		var	testElement = S('#field1_sub0 input[name=Uart1Hidden]'),
			observableElement = S('#field1_sub0 select[name=__RCC_CFGR_VAL_18_21]');

		equal(observableElement.length, 1, 'control __RCC_CFGR_VAL_18_21 found.');
		ok(true, 'control __RCC_CFGR_VAL_18_21 value ' + observableElement.val());
		equal(testElement.length, 1, 'test control Uart1Hidden found.');
		ok(true, 'test control Uart1Hidden value ' + testElement.val());
		if (observableChange) {
			observableElement[0].value = '1';
			observableElement.change();
			ok(true, 'control __RCC_CFGR_VAL_18_21 value ' + observableElement.val());
			S.wait(1000, function() {
				equal(testElement.val(), '1U', 'test control Uart1Hidden changed value to 1U correctly.');
			});
		}
	});
	///////////////////////////////////////////// Radio ////////////////////////////////////////////////////////////
	module("Observable Tests for Radio Fields.");
	test("Single Test", function() {
		var	testElement = S('#field1_sub0 input[name=RadioHidden]'),
			observableElement = S('#field1_sub0 input:radio[name=UART0BaudrateRadio]'),
			observableCheckedElement = S('#field1_sub0 input:radio[name=UART0BaudrateRadio]:checked');;

		equal(observableElement.length, 3, 'control UART0BaudrateRadio found.');
		equal(observableCheckedElement.length, 1, "control UART0BaudrateRadio Checked found.");
		equal(observableCheckedElement.val(), "4800", 'control UART0BaudrateRadio value 4800 checked.');
		equal(testElement.length, 1, 'test control RadioHidden found.');
		ok(true, 'test control RadioHidden value ' + testElement.val());
		if (observableChange) {
			observableElement[0].checked = false;
			observableElement[1].checked = true;
			observableElement.change();
			observableCheckedElement = S('#field1_sub0 input:radio[name=UART0BaudrateRadio]:checked');
			equal(observableCheckedElement.length, 1, "control UART0BaudrateRadio Checked found.");
			equal(observableCheckedElement.val(), "9600", 'control UART0BaudrateRadio value 9600 checked.');
			S.wait(500, function() {
				equal(testElement.val(), '1U', 'test control RadioHidden changed value to 1U correctly.');
			});
		}
	});
	///////////////////////////////////////////// Checkbox ////////////////////////////////////////////////////////////
	module("Observable Tests for Checkbox Fields.");
	test("Single Test", function() {
		var	testElement = S('#field1_sub0 input[name=CheckBoxHidden]'),
			observableElement = S('#field1_sub0 div[name=UART1EnableINTCheckbox]');

		equal(observableElement.length, 3, 'control UART1EnableINTCheckbox found.');
		equal(testElement.length, 1, 'test control CheckBoxHidden found.');
		ok(true, 'test control CheckBoxHidden value ' + testElement.val());
		if (observableChange) {
			observableElement[0].children[0].children[0].checked= false;
			observableElement[1].children[0].children[0].checked= true;
			observableElement[2].children[0].children[0].checked= false;
			observableElement.change();
			S.wait(500, function() {
				equal(testElement.val(), '1U', 'test control CheckBoxHidden changed value to 1U correctly.');
			});
		}
	});
	///////////////////////////////////////////// CheckboxBoolean ////////////////////////////////////////////////////////////
	module("Observable Tests for CheckboxBoolean Fields.");
	test("Single Test", function() {
		var observableChange = true;

		var	testElement = S('#field1_sub0 input[name=CheckBoxBooleanHidden]'),
			observableElement = S('#field1_sub0 div[name=UART1EnableINTCheckboxBoolean]');

		equal(observableElement.length, 1, 'control UART1EnableINTCheckboxBoolean found.');
		equal(testElement.length, 1, 'test control CheckBoxBooleanHidden found.');
		ok(true, 'test control CheckBoxBooleanHidden value ' + testElement.val());
		if (observableChange) {
			observableElement[0].children[0].children[0].checked= true;
			observableElement.change();
			S.wait(500, function() {
				equal(testElement.val(), '1U', 'test control CheckBoxBooleanHidden changed value to 1U correctly.');
			});
		}
	});
	///////////////////////////////////////////// MultipleSelect ////////////////////////////////////////////////////////////
	module("Observable Tests for MultipleSelect Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 input[name=MultipleSelectHidden]'),
			observableElement = S('#field1_sub0 select[name=UART1DisableINTMultipleSelect]');

		equal(observableElement.length, 1, 'control UART1DisableINTMultipleSelect found.');
		ok(true, 'control UART1DisableINTMultipleSelect value ' + observableElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.length, 1, 'test control MultipleSelectHidden found.');
		ok(true, 'test control MultipleSelectHidden value ' + testElement.val());
		if (observableChange) {
			observableElement[0].value = "UART_INTEN_THREIEN_Msk";
			observableElement.change();
			ok(true, 'control UART1DisableINTMultipleSelect value ' + observableElement.val());
			S.wait(500, function() {
				equal(testElement.val(), '1U', 'test control MultipleSelectHidden changed value to 1U correctly.');
			});
		}
	})
	test("NUC_ANY Test", function() {
		var testElement = S('#field1_sub0 input[name=MultipleSelectHidden1]'),
			observableElement = S('#field1_sub0 select[name=TIMER0TriggerTargetMultipleSelect]');

		equal(observableElement.length, 1, 'control TIMER0TriggerTargetMultipleSelect found.');
		ok(true, 'control TIMER0TriggerTargetMultipleSelect value ' + observableElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.length, 1, 'test control MultipleSelectHidden1 found.');
		ok(true, 'test control MultipleSelectHidden1 value ' + testElement.val());
		if (observableChange) {
			observableElement[0].value = "TIMER_TRGCTL_TRGDAC_Msk";
			observableElement.change();
			ok(true, 'control TIMER0TriggerTargetMultipleSelect value ' + observableElement.val());
			S.wait(500, function() {
				equal(testElement.val(), '1U', 'test control MultipleSelectHidden1 changed value to 1U correctly.');
			});
		}
	})
	///////////////////////////////////////////// Integer ////////////////////////////////////////////////////////////
	module("Observable Tests for Integer Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 input[name=IntegerHidden]'),
			observableElement = S('#field1_sub0 input[name=UART1BaudrateInteger]');

		equal(observableElement.length, 1, 'control UART1BaudrateInteger found.');
		ok(true, 'control UART1BaudrateInteger value ' + observableElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.length, 1, 'test control IntegerHidden found.');
		ok(true, 'test control IntegerHidden value ' + testElement.val());
		if (observableChange) {
			observableElement[0].value = "115200";
			observableElement.change();
			ok(true, 'control UART1BaudrateInteger value ' + observableElement.val());
			S.wait(500, function() {
				equal(testElement.val(), '115200U', 'test control IntegerHidden changed value to 115200U correctly.');
			});
		}
	});
	///////////////////////////////////////////// HexText ////////////////////////////////////////////////////////////
	module("Observable Tests for HexText Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 input[name=HexTextHidden]'),
			observableElement = S('#field1_sub0 input[name=Timer0InputHexText]');

		equal(observableElement.length, 1, 'control Timer0InputHexText found.');
		ok(true, 'control Timer0InputHexText value ' + observableElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.length, 1, 'test control HexTextHidden found.');
		ok(true, 'test control HexTextHidden value ' + testElement.val());
		if (observableChange) {
			observableElement[0].value = "115200";
			observableElement.change();
			ok(true, 'control Timer0InputHexText value ' + observableElement.val());
			S.wait(500, function() {
				equal(testElement.val(), '115200U', 'test control HexTextHidden changed value to 115200U correctly.');
			});
		}
	});
}(jQuery) );
